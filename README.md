# Console Chess ♟️

Este repositorio contiene el diagrama UML del proyecto "Console Chess", un videojuego de ajedrez programado en C++ para ser jugado en la consola.

## UML Diagrama de Clases

El diagrama UML representa la estructura de clases del proyecto, mostrando las relaciones de herencia y composición entre las diferentes clases.

![UML](uml/uml.png)

## Avances

### Creación de las clases

Se han creado las clases principales del proyecto, con sus respectivos atributos y métodos. Se han definido las relaciones de herencia y composición entre las clases.

La declaración e implementación de las clases están en archivos distintos debido a que ocurrían errores dado a que existía una dependencia circular entre las clases `Piece` y `Board`.

### Algortimo de movimiento de piezas

Se ha implementado los métodos `Piece::isValidMove()` que comprueba si un movimiento es válido para una pieza, y el método `Board::movePiece()` que mueve una pieza de una posición a otra.

### Implementación de polimorfismo

Se ha implementado el polimorfismo en las clases `Piece` y `Board`, de tal manera que `Board` tenga un atributo de tipo `Piece` y pueda acceder a los métodos de las clases hijas de `Piece` (por ejemplo, `Piece::move()`).

### Implementación de clases abstractas

Se ha implementado la clase abstracta `Piece`, que contiene los métodos virtuales puros `Piece::move()` y `Piece::print()`. Se pueden crear objetos de tipo `Piece` con polimorfismo, pero no se pueden crear objetos de tipo `Piece` directamente.

### Implementación de la clase `Game`

Se ha implementado la clase `Game`, que contiene los métodos necesarios para jugar una partida de ajedrez. Se ha implementado el método `Game::playGame()` que permite jugar una partida de ajedrez.

### Validar jaque, jaquemate y rey ahogado

Se ha implementado el método `Game::isCheck()` que comprueba si un jugador está en jaque. Además, para evitar que un jugador pueda mover una pieza que deje a su rey en jaque, se ha implementado el método `Game::isCheckAfterMove()` que crea una copia del tablero, mueve la pieza y comprueba si el rey del jugador está en jaque, y si es así, no permite mover la pieza. También se ha implementado el método `Game::isCheckmate()` que comprueba si un jugador está en jaque mate, probando todos los movimientos posibles de todas las piezas del jugador y comprobando si el rey del jugador sigue en jaque después de cada movimiento. Por último, se ha implementado el método `Game::isStalemate()` que comprueba si un jugador no puede mover ninguna pieza, pero su rey no está en jaque, por lo que se produce un rey ahogado.