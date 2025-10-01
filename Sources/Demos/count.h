#pragma once
#include "Core/Application.h"
#include "Core/Math/Random.h"
#include "Core/Math/Vector2.h"
#include <vector>


namespace nkentseu{
    class Count : public Application {
        private:
      
        public:
        Count(const ApplicationProperties& props) ;
        protected:
            void Setup() override;
            void Update(float deltaTime) override;
            void Draw() override;
         math::Vector2 position;
        float gravity=9.81f;
        float r= 100.0f;
        float friction = 20.0f;
    };
}
