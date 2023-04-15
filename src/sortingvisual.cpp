#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "Rectangle.h"

void swap(Rectangle&, Rectangle&);
void drawShapes(std::vector<Rectangle>, sf::RenderWindow&);
void bubbleSort(std::vector<Rectangle>&, sf::RenderWindow&);
bool isSorted(std::vector<Rectangle>);

unsigned int WIND_WIDTH = 800; //Window width
unsigned int WIND_HEIGHT = 800; //Window height
int ground = WIND_HEIGHT - 1; //Y coordinate of the very bottom of the window

int main()
{
    int arr_size = 200; //Size of the array

    sf::RenderWindow window(sf::VideoMode(WIND_WIDTH, WIND_HEIGHT), "Sorting Visual");

    //For random number generator
    srand((unsigned) time(NULL)); //Seed for rand

    std::vector<Rectangle> rectarr; //Array of Rectangles

    int x_off = 0; //x offset as we populate the rectangles x position
    for (int i = 0; i < arr_size; i++)
    {
        float random = 1 + (rand() % WIND_HEIGHT); //Random number between 1 and the window height
        Rectangle temprect((WIND_WIDTH / arr_size), random, x_off, ground - random); 
        rectarr.push_back(temprect);
        x_off += (WIND_WIDTH / arr_size); //Move offset
    }

    window.clear();
    drawShapes(rectarr, window);
    window.display();
    
    bool start = false; //Algorithm starts or not
    while (window.isOpen()) //Main Loop
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if ((event.type == sf::Event::KeyReleased) && (event.key.code ==  sf::Keyboard::Space)) //If space bar is entered 
            {
                start = true;
            }
        }

        if (start)
        {
           bubbleSort(rectarr, window);
           start = false;
        }

        if (isSorted(rectarr))
        {
            for (int i = 0; i < rectarr.size(); i++) //Change each rectangle to green
            {
                rectarr[i].color = sf::Color(10, 255, 75);
                window.clear();
                drawShapes(rectarr, window);
                window.display();
                sf::sleep(sf::milliseconds(15));
            }
        }

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

    lhs.color = sf::Color(255,255,255);
    rhs.color = sf::Color(255,255,255);

    sf::sleep(sf::milliseconds(3));
}

/*Draws all rectangles to the window*/
void drawShapes(std::vector<Rectangle> rectarr, sf::RenderWindow& window)
{
    for (int i = 0; i < rectarr.size(); i++)
    {
        sf::RectangleShape temp;
        temp = rectarr[i].setShape();
        window.draw(temp);
    }
}

/*Bubble Sort Algorithm*/
void bubbleSort(std::vector<Rectangle>& rectarr, sf::RenderWindow& window)
{
    for (int i = 0; i < rectarr.size() - 1; i++)
    {
        for (int j = 0; j < rectarr.size() - i - 1; j++)
        {
            window.clear();
            drawShapes(rectarr, window);
            window.display();
            if (rectarr[j] > rectarr[j + 1])
            {
                swap(rectarr[j], rectarr[j + 1]);
            }
        }
    }
}

/*Return true if all elements in the array is sorted*/
bool isSorted(std::vector<Rectangle> rectarr)
{
    for (int i = 0; i < rectarr.size() - 1; i++)
    {
        if (rectarr[i].height > rectarr[i + 1].height)
        {
            return false;
        }
    }
    
    return true;
}