#include "DemoParticles.h"
#include "Core/Log.h"
#include "Core/Math/Random.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>

namespace nkentseu {

   
        
       
          
    // DemoParticles methods
     DemoParticles::DemoParticles(const ApplicationProperties& props) 
        : Application(props), randomGenerator(std::random_device{}()), randomFloat(0.0f, 1.0f) {
        
        
    } 

    void DemoParticles::Setup() {
       walker.push_back(math::Vector2(10,10));
    

     }

    void DemoParticles::Update(float deltaTime) {
         walker[0]+=math::Vector2(math::Random::Range<int>(-1,1),math::Random::Range<int>(-1,1));
       
    }

    void DemoParticles::Draw() {
        Background(graphics::Color::White);

        Fill(graphics::Color::White);
        Stroke(graphics::Color(128,128,128,255));


        int largeur = GetWindowWidth();
        int hauteur =GetWindowHeight();
        int size = 10;
        int col = largeur / size;
        int linc = hauteur/ size;


        for (int i =0;i< col;i++){
            for(int j=0;j<linc;j++){
                Rect(math::Vector2 (i*size,j*size),
                math::Vector2(size,size));
            }
        }
        Fill(graphics::Color::Red);
        for (auto walk:walker){
            Rect(math::Vector2(walk.x*size,walk.y*size),
        math::Vector2(size,size));
        }
    } 

}
