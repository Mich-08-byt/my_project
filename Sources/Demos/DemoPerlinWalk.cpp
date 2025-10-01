#include "DemoPerlinWalk.h"

namespace nkentseu {
    DemoPerlinWalk::DemoPerlinWalk(const ApplicationProperties& props)
    :Application(props), tx(0.0f), ty(10000.0f) {}

    void DemoPerlinWalk::Setup() {
        position = math::Vector2(GetWindowWidth() /2.0f, GetWindowHeight() /2.0f);
        Background(graphics::Color::White);
    }

    void DemoPerlinWalk::Update(float deltaTime){
        
    }

    void DemoPerlinWalk::Draw() {
        //dessiner le marcheur
        Fill(graphics::Color::Black);
        NoStroke();
        Circle(position, 4.0f);

        //utiliser le bruit de perlin pour la position
        float noiseX = math::Random::Noise(tx);// utilise la loi de probablite (Noise) pour le bruit de perlin
        float noiseY = math::Random::Noise(ty);

        //mapper de [0, 1] à la taille de la fenetre
        position.x = math::Random::Map(noiseX, 0.0f, 1.0f, 0.0f, (float)GetWindowWidth());
        position.y = math::Random::Map(noiseY, 0.0f, 1.0f, 0.0f, (float)GetWindowHeight());

        //avancer dans l'"esace-temps" du bruit
        tx += 0.01f;
        ty += 0.01f;
    }
}
//fonction de creation
nkentseu::Application* CreatePerlinWalkDemo(const nkentseu::ApplicationProperties& props) {
    return new nkentseu::DemoPerlinWalk(props);
}