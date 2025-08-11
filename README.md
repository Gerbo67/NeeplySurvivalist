NeeplySurvivalist (MVP) 🎮
🏙️ Descripción del Proyecto

NeeplySurvivalist es un prototipo funcional (MVP) de un juego de supervivencia en primera persona ambientado en una ciudad post-apocalíptica. Construido con un distintivo estilo Voxel, el objetivo es simple: sobrevivir a las hordas de zombis 🧟 que deambulan por las desoladas calles.

Este proyecto fue desarrollado en Unreal Engine 5.6 como entrega final para la materia de Motores Gráficos de la Universidad Cuauhtémoc Querétaro 🎓. Sirve como una demostración de mecánicas de juego, inteligencia artificial y la integración de diferentes sistemas y assets.
📦 Estado Actual: MVP (Minimum Viable Product)

Este repositorio contiene la versión MVP del juego. Esto significa que las características principales están implementadas y son funcionales ✅, pero el alcance está limitado para demostrar la viabilidad del concepto. Es una base sólida sobre la cual se puede construir un juego completo.
✨ Características Principales

    Supervivencia Voxel: Explora un entorno urbano con una estética voxel que le da un estilo visual único.

    IA de Zombis Avanzada 🧠: Los enemigos no solo persiguen al jugador, sino que utilizan un sistema de Búsqueda de Mejor Camino (Environment Query System - EQS) para navegar el entorno de forma inteligente y encontrar la ruta más óptima hacia el jugador.

    Combate Directo 💥: Los zombis requieren 5 impactos de bala para ser eliminados, obligando al jugador a gestionar sus recursos.

    Sistema de Muerte Dinámico 💀: Al morir el jugador, se selecciona de forma aleatoria una de las 3 animaciones de muerte disponibles, añadiendo variedad a la experiencia.

⚙️ Detalles Técnicos

El núcleo del juego fue construido priorizando el rendimiento y la escalabilidad, combinando la potencia de C++ con la flexibilidad de los Blueprints.

    Motor: Unreal Engine 5.6

    Lógica Principal 💻: La mayoría de las mecánicas de juego, sistemas de daño y la lógica del jugador están escritas en C++ para un rendimiento óptimo.

    Inteligencia Artificial 🤖:

        Se utilizan Behavior Trees (Árboles de Comportamiento) para definir los estados y decisiones de los zombis (patrullar, perseguir, atacar).

        La búsqueda de rutas se realiza mediante una tarea personalizada en C++ que invoca el Environment Query System (EQS) de Unreal Engine, como se ve en el UBTTask_FindBestPathToPlayer. Esto permite a los zombis analizar el entorno y tomar decisiones de navegación complejas.

    Animaciones 🎨: El sistema de animación se gestiona a través de Blueprints, permitiendo una iteración y ajuste visual más rápido.

🚀 El Viaje del Desarrollo: Retos y Soluciones

El desarrollo de este MVP fue un gran aprendizaje, especialmente en la integración de assets de distintas fuentes y épocas.

    Assets de Zombis 🧩: Los modelos de los zombis fueron adquiridos en la Tienda de Assets de Unity y databan originalmente de 2018. Migrarlos a un proyecto de Unreal Engine 5.6 en 2025 presentó numerosos desafíos. Fue necesario redefinir esqueletos, adaptar materiales y corregir jerarquías de huesos para que funcionaran correctamente con el sistema de animación de Unreal.

    Assets del Entorno: Los edificios y elementos de la ciudad se compraron en itch.io, seleccionados por su compatibilidad con el estilo voxel.

    Filosofía Híbrida 🔧: Se adoptó un enfoque híbrido, utilizando C++ para la lógica subyacente que requiere rendimiento y Blueprints para tareas de alto nivel como la gestión de animaciones y la configuración de eventos, aprovechando lo mejor de ambos mundos.

🗺️ Metas Futuras (La Visión del Juego Completo)

Aunque este MVP es funcional, la visión original incluía varias características que no se lograron implementar por cuestiones de tiempo. Sirven como la hoja de ruta para el futuro desarrollo:

    Finalizar el Diseño de la Ciudad: Expandir y completar el mapa urbano con más zonas para explorar.

    Spawn Aleatorio del Jugador 🎲: Implementar un sistema que coloque al jugador en un punto de inicio diferente en cada sesión para aumentar la rejugabilidad.

    Variedad de Animaciones Pasivas 🕺: Asignar una animación idle (en reposo) diferente y aleatoria a cada zombi al generarse, para darles un aspecto más natural y menos uniforme.
