struct Rectangle {
    float width, height;
    float x, y; //x and y coordinate

    sf::RectangleShape setShape();

    Rectangle() {};

    Rectangle(float width, float height, float x, float y)
    {
        this->width = width;
        this->height = height;
        this->x = x;
        this->y = y;
    }

    friend bool operator >(const Rectangle& lhs, const Rectangle& rhs)
    {
        return lhs.height > rhs.height;
    }
};

sf::RectangleShape Rectangle::setShape()
{
    return sf::RectangleShape(sf::Vector2f(width, height)); 
}

