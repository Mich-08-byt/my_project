#include "DemoRandomWalk.h"


namespace nkentseu {

    DemoRandomWalk::DemoRandomWalk(const ApplicationProperties& props)
        : Application(props) {
        histogram.resize(GetWindowWidth(), 0); // init histogramme
    }

    void DemoRandomWalk::Setup() {
        position = math::Vector2(GetWindowWidth() / 2.0f, GetWindowHeight() / 2.0f);
        Background(graphics::Color::White);
    }

    void DemoRandomWalk::Update(float deltaTime) {
    }

    void DemoRandomWalk::Draw() {
        // Dessiner le marcheur actuel
        Fill(graphics::Color::Black);
        NoStroke();
        Circle(position, 4.0f);

        //Distribution non_uniforme : 40% droite , 20% autres directions
        /* float r = math::Random::Value();
        if (r<0.4f){
            position.x++; //40% droite
        } else if (r<0.6f){
            position.x--;  //20% gauche
        } else if (r<0.8f){
            position.y++; //20% bas
        } else {
            position.y--; //20% haut
        }
 */
        //prendre un pas aleatoire
        int choice = math::Random::Range(0, 3);

        if (choice == 0){
            position.x++;
        }else if (choice == 1){
            position.x--;
        }else if (choice == 2){
            position.y++;
        }else{
            position.y--;
        }

         // Mouvement avec distribution gaussienne 
        float stepX = math::Random::Gaussian(0.0f, 2.0f); //utilise la loi de (Gaussian ) pour non uniforme
        float stepY = math::Random::Gaussian(0.0f, 2.0f); 
     
        position.x += stepX; 
        position.y += stepY; 

         //  Garder dans les limites de l'écran
        position.x = std::max(0.0f, std::min(position.x, (float)GetWindowWidth() - 1));
        position.y = std::max(0.0f, std::min(position.y, (float)GetWindowHeight() - 1));



           // === 2. Calcul de direction vers la souris ===
        math::Vector2 mousePos = GetMousePosition();
        math::Vector2 direction = mousePos - position;

        if (direction.Magnitude() > 0) {
            direction = direction.Normalized();
        }

        // === 3. Choix du déplacement (70% vers souris, 30% gaussien) ===
        float r = math::Random::Value();
        if (r < 0.7f) {
            // Attraction vers souris
            position = position + direction;
        } else {
            // Déplacement gaussien
            float stepX = math::Random::Gaussian(0.0f, 2.0f);
            position.x += stepX;
        } 

        // === 5. Mettre à jour l’histogramme ===
      /*   histogram[(int)position.x]++;

        // === 6. Effacer l’écran et tracer histogramme ===
        Background(graphics::Color::White);

        for (int i = 0; i < histogram.size(); i++) {
            int h = histogram[i];
            if (h > 0) {
                Fill(graphics::Color::Black);
                NoStroke();
                Rect(math::Vector2(i, GetWindowHeight() - h),
                     math::Vector2(1, h));
            }
        }
 */

    }

    }
        
/* 
        // === 7. Redessiner le marcheur au-dessus de l’histogramme ===
        Fill(graphics::Color::Black);
        NoStroke();
        Circle(position, 4.0f);
    } */


// Fonction de création
nkentseu::Application* CreateRandomWalkDemo(const nkentseu::ApplicationProperties& props) {
    return new nkentseu::DemoRandomWalk(props);
}