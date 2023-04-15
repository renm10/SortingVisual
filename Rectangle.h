struct Rectangle {
    float width, height;
    float x, y; //x and y coordinate

    sf::Color color = sf::Color(255,255,255); //Default white

    sf::RectangleShape setShape();

    Rectangle() {}; //Default Constructor

    Rectangle(float width, float height, float x, float y)
    {
        this->width = width;
        this->height = height;
        this->x = x;
        this->y = y;
    }

    friend bool operator >(const Rectangle& lhs, const Rectangle& rhs) // > operator overload
    {
        return lhs.height > rhs.height;
    }
};

sf::RectangleShape Rectangle::setShape() //Sets the sf::RectangleShape object given this Rectangle.
{
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(x,y);
    return rect;
}

