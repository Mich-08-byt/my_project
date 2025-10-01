#pragma once
#include "Core/Application.h"
#include "Core/Math/Random.h"
#include "Core/Math/Vector2.h"
#include <vector>


namespace nkentseu{
    class DemoRandomWalk : public Application {
        private:
        math::Vector2 position;// la position du marcheur
         std::vector<int> histogram;    // l’histogramme pour compter
        
        public:
        DemoRandomWalk(const ApplicationProperties& props) ;
        protected:
            void Setup() override;
            void Update(float deltaTime) override;
            void Draw() override;
    };
}
