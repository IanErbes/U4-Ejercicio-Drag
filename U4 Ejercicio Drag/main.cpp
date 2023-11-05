#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {

    Texture texture_punto_rojo;
    texture_punto_rojo.loadFromFile("rcircle.png");

    Sprite sprite_punto_rojo;
    sprite_punto_rojo.setTexture(texture_punto_rojo);

    RenderWindow App(VideoMode(800, 600, 32), "Ejercicio 2 drag");

    App.setMouseCursorVisible(false);

    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed) {
                App.close();
            }
        }

        Vector2i mousePosition = Mouse::getPosition(App);

        Vector2u spriteSize = texture_punto_rojo.getSize();

        // Método para mover el sprite en relación a la posicion del mouse
        sprite_punto_rojo.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

        // Busque un método para que el circulo rojo no se saliera de la pantalla, ya que me pasaba eso al principio
        if (sprite_punto_rojo.getPosition().x < 0) {
            sprite_punto_rojo.setPosition(0, sprite_punto_rojo.getPosition().y);
        }
        if (sprite_punto_rojo.getPosition().x + spriteSize.x > App.getSize().x) {
            sprite_punto_rojo.setPosition(App.getSize().x - spriteSize.x, sprite_punto_rojo.getPosition().y);
        }
        if (sprite_punto_rojo.getPosition().y < 0) {
            sprite_punto_rojo.setPosition(sprite_punto_rojo.getPosition().x, 0);
        }
        if (sprite_punto_rojo.getPosition().y + spriteSize.y > App.getSize().y) {
            sprite_punto_rojo.setPosition(sprite_punto_rojo.getPosition().x, App.getSize().y - spriteSize.y);
        }

        App.clear();

        App.draw(sprite_punto_rojo);

        App.display();
    }

    return 0;
}