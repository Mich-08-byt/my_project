/* #include "DemoParticles.h"
#include "Core/Log.h"

#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>

namespace nkentseu {
    void DemoParticles::Setup(){

    }
    void DemoParticles::Update(float deltaTime){

    }
     void DemoParticles::Draw() {
         Background(graphics::Color(0, 0, 0, 255));
        
        for (const auto& grid : grid) {
            Drawgrid(grid);
        }
        
        DrawFireBase();
        DrawInfo(); 
    }
     bool DemoParticles::ConfigFileProvided(const std::vector<std::string>& args) const {
        for (size_t i = 0; i < args.size(); ++i) {
            if (args[i] == "--fire-config" && i + 1 < args.size()) {
                return true;
            }
        }

    }

 }   
filled(graphics::color::white) */
/* 
#include "DemoRandomWalk.h"
#include <vector>

namespace nkentseu{
        DemoRandomWalk::DemoRandomWalk(const ApplicationProperties& props)
            :Application(props) {
                histogram.resize(GetWindowWidth(), 0); // un compteur par colonne de pixel
            } 

    void DemoRandomWalk::Setup() {
        position = math::Vector2(GetWindowWidth() / 2.0f, GetWindowHeight() / 2.0f);
        Background(graphics::Color::White); 
    }
    void DemoRandomWalk::Update(float deltaTime) {
        //la logique de mise a jour sera dans Draw pour cet exemple simple 
    }

    void DemoRandomWalk::Draw() {
         // Mouvement avec distribution gaussienne
            float stepX = math::Random::Gaussian(0.0f, 2.0f); 
            position.x += stepX;

            // Garder dans les limites
            position.x = std::max(0.0f, std::min(position.x, (float)GetWindowWidth() - 1));

            // Incrémenter le compteur pour cette position
            histogram[(int)position.x]++;

            // Effacer l’écran
            Background(graphics::Color::White);

            // Dessiner l’histogramme
            for (int i = 0; i < histogram.size(); i++) {
                int h = histogram[i];
                if (h > 0) {
                    Fill(graphics::Color::Black);
                    NoStroke();
                    Rect(math::Vector2(i, GetWindowHeight() - h), math::Vector2(1, h));
                }
            }   
           

        
        //Dessiner le marcheur
        Fill(graphics::Color::Black);
        NoStroke();
        Circle(position, 4.0f);

        //obtenir la position de la souris
        math::Vector2 mousePos = GetMousePosition();

        //calculer le vecteur direction entre marcheur et souris
        math::Vector2 direction = mousePos - position;

        //normaliser (pour garder une petite vitesse)
        if (direction.Magnitude() > 0) {
            direction = direction.Normalized();
        }

       //mouvevement avec distribution gaussienne
         float stepX = math::Random::Gaussian(0.0f, 2.0f);
        float stepY = math::Random::Gaussian(0.0f, 2.0f);

        position.x += stepX;
        position.y += stepY; 

        //distibutioon non-uniforme: 40% droite, 20% autres directions

        //deplacement : melange entre hasard et attraction vers la souris

        float r = math::Random::Value();
        if(r<0.7f){
            position = position + direction;
        }

        if (r < 0.4f) {
            position.x++; //40% droite
        }else if (r < 0.6f) {
            position.x--; //20% gauche
        }else if (r< 0.8f) {
            position.y++; //20% bas
        }else{
            position.y--; // 20% haut
        } 
 
        else{

        // prendre un pas aleatoire
        int choice = math::Random::Range(0,3);

        if (choice == 0){
            position.x++;
        } else if (choice == 1){
            position.x--;
        } else if (choice == 2){
            position.y++;
        } else{
            position.y--;
        }

    }
        //garder dans les limites de l'ecran
        position.x = std::max(0.0f, std::min(position.x, (float)GetWindowWidth()));
        position.y = std::max(0.0f, std::min(position.y, (float)GetWindowHeight()));
}

}

//fonction de creation
nkentseu::Application* CreateRandomWalkDemo(const nkentseu::ApplicationProperties& props){
    return new nkentseu::DemoRandomWalk(props);
} */