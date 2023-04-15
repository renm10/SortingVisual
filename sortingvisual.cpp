#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "Rectangle.h"

void swap(Rectangle&, Rectangle&);
void drawShapes(std::vector<Rectangle>, sf::RenderWindow&);
void bubbleSort(std::vector<Rectangle>&);

unsigned int WIND_WIDTH = 400;
unsigned int WIND_HEIGHT = 400;
int ground = WIND_HEIGHT - 1; //Y coordinate of the very bottom of the window

int main()
{
    int arr_size = 50; //Size of the array

    sf::RenderWindow window(sf::VideoMode(WIND_WIDTH, WIND_HEIGHT), "Sorting Visual");

    //For random number generator
    srand((unsigned) time(NULL)); //Seed for rand

    std::vector<Rectangle> rectarr;

    int x_off = 0; //x offset as we populate the rectangles x position
    for (int i = 0; i < arr_size; i++)
    {
        float random = 1 + (rand() % 100);
        Rectangle temprect((WIND_WIDTH / arr_size), random, x_off, ground - random);
        rectarr.push_back(temprect);
        x_off += (WIND_WIDTH / arr_size);
        std::cout << "Creating a Rectangle with: " << std::endl;
        std::cout << "Width: " <<  temprect.width << " Height: " << temprect.height << " x: "
        << temprect.x << " y: " << temprect.y << std::endl; 
    }
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    bubbleSort(rectarr);
                }
            }
        }
       
        window.clear();
        drawShapes(rectarr, window);
        window.display();
    }

    return 0;
}

/*Swaps the value(height) and changes its y-coordinate according to its height*/
void swap(Rectangle& lhs, Rectangle& rhs)
{
    Rectangle temp;
    temp.height = lhs.height;
    temp.y = ground - lhs.height;

    lhs.height = rhs.height;
    lhs.y = ground - rhs.height;

    rhs.height = temp.height;
    rhs.y = temp.y;
}

void drawShapes(std::vector<Rectangle> rectarr, sf::RenderWindow& window)
{
    for (int i = 0; i < rectarr.size(); i++)
    {
        sf::RectangleShape temp;
        temp = rectarr[i].setShape();
        temp.setFillColor(sf::Color(150,50,250));
        temp.setPosition(rectarr[i].x, rectarr[i].y);
        window.draw(temp);
    }
}

void bubbleSort(std::vector<Rectangle>& rectarr)
{
    for (int i = 0; i < rectarr.size(); i++)
    {
        for (int j = 0; j < rectarr.size() - i - 1; j++)
        {
            if (rectarr[j] > rectarr[j + 1])
            {
                swap(rectarr[j], rectarr[j + 1]);
            }
        }
    }
}