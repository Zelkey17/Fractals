//
// Created by ash on 27.09.22.
//

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>


#ifndef GRAPHICS_MAIN_WINDOW_H
#define GRAPHICS_MAIN_WINDOW_H


namespace GraphicsProject {

    class MainWindow {

        MainWindow() = default;

        void init();

        sf::RenderWindow window;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2i win_size;
        sf::Vector2<double> zoom;
        sf::Vector2<double> ul_coord;
        uint8_t *pix = nullptr;


        void update();

        sf::Color color(int i, int j) const;

    public:
        MainWindow(const std::string &title, const sf::Vector2i &size);

        void start();
    };

} // GraphicsProject

#endif //GRAPHICS_MAIN_WINDOW_H
