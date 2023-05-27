//
// Created by ash on 27.09.22.
//
#include "MainWindow.h"
#include "Complex.h"
#include<fstream>

namespace GraphicsProject {
    void MainWindow::start() {
        sf::Vector2i local_point = sf::Mouse::getPosition(window);
        while (window.isOpen()) {
            sf::Event event{};

            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    window.close();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    ul_coord.x += (float) (local_point.x - sf::Mouse::getPosition(window).x) / zoom.x;
                    ul_coord.y += (float) (local_point.y - sf::Mouse::getPosition(window).y) / zoom.y;
                }
                local_point = sf::Mouse::getPosition(window);


                if (event.type == sf::Event::MouseWheelScrolled) {
                    double x = local_point.x / zoom.x + ul_coord.x,
                            y = -local_point.y / zoom.y - ul_coord.y;

                    ul_coord.x = x - (x - ul_coord.x) / (zoom.x * pow(1.1, event.mouseWheelScroll.delta)) * zoom.x;
                    zoom.x *= pow(1.1, event.mouseWheelScroll.delta);

                    ul_coord.y = (y + ul_coord.y) / (zoom.y * pow(1.1, event.mouseWheelScroll.delta)) * zoom.y - y;
                    zoom.y *= pow(1.1, event.mouseWheelScroll.delta);

                }

            }
            update();
        }

    }

    MainWindow::MainWindow(const std::string &title, const sf::Vector2i &size) :
            window(sf::VideoMode(size.x, size.y), title),
            win_size(size),
            zoom(35, 35),
            ul_coord(-(win_size.x / zoom.x) / 2.f, -(win_size.y / zoom.y) / 2.f) {
        init();

    }

    void MainWindow::init() {

        pix = new uint8_t[win_size.x * win_size.y * 4];
        texture.create(win_size.x, win_size.y);
        sprite.setTexture(texture);
    }

    void MainWindow::update() {
        window.clear({255, 255, 255, 255});
        for (int i = 0; i < win_size.y; i++) {
            for (int j = 0; j < win_size.x; j++) {
                sf::Color clr = color(i, j);
                pix[(i + j * win_size.y) * 4] = clr.r;
                pix[(i + j * win_size.y) * 4 + 1] = clr.g;
                pix[(i + j * win_size.y) * 4 + 2] = clr.b;
                pix[(i + j * win_size.y) * 4 + 3] = clr.a;
            }
        }
        texture.update(pix);
        window.draw(sprite);
        window.display();
    }

    sf::Color MainWindow::color(int i, int j) const {
        double x = (double) (i) / zoom.x + ul_coord.x,
                y = (double) (-j) / zoom.y - ul_coord.y;
        Complex a = {0, 0};
        Complex b = {x, y};
        unsigned char cnt = 0;
        while (a.len() < 2 && cnt < 200) {
            a = a * a + b;
            cnt++;
        }

        return {static_cast<sf::Uint8>((cnt == 200) ? 0 : std::max(0., 255 / pow(10. / zoom.x + 1, cnt))),
                static_cast<sf::Uint8>((cnt == 200) ? 0 : 255 / pow(5. / zoom.x + 1.01, cnt)),
                static_cast<sf::Uint8>((cnt == 200) ? 0 : 255 / pow(20. / zoom.x + (1 + zoom.x / 200000.), cnt))};
    }

} // GraphicsProject

