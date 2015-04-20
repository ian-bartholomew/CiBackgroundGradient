#pragma once

#include "cinder/app/AppBasic.h"

using namespace std;
using namespace cinder;

namespace bggradient {
    
class BackgroundGradient {
    public:
        BackgroundGradient();
        ~BackgroundGradient();
    
        gl::VboMeshRef static   buildGradient( const Color& start, const Color& stop, float w, float h);
    
    private:
        float               mWidth, mHeight;
        gl::VboMeshRef      mGradientMesh;
    };
}