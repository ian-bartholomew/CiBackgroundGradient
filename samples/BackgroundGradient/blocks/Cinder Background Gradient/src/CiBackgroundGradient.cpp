#include "CiBackgroundGradient.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/Vbo.h"

using namespace ci;
using namespace ci::app;
using namespace std;

namespace bggradient {
    
    gl::VboMeshRef BackgroundGradient::buildGradient(const Color& start, const Color& stop, float w, float h){
        
        Vec2f center(w * 0.5f, h * 0.5f);
        
        size_t slices = 36;
        
        std::vector<Vec2f> texcoords;
        std::vector<uint32_t> indices;
        std::vector<Color> colors;
        std::vector<Vec3f> positions;
        
        indices.push_back( positions.size() );
        positions.push_back( Vec3f(w * 0.5f, h * 0.5f, 0) );
        colors.push_back(start);
        
        float angleBisector = (2* M_PI) / (slices * 2);
        float smallRadius = center.distance(Vec2f(0,0));
        float bigRadius = smallRadius / cos(angleBisector);
        
        for(size_t i=0;i<=slices;++i) {
            float angle = i / (float) slices * (2*M_PI);
            Vec2f v(sinf(angle), cosf(angle));
            
            indices.push_back( positions.size() );
            positions.push_back( Vec3f(center,0.0f) + Vec3f(v, 0.0f) * bigRadius );
            colors.push_back(stop);
        }
        
        
        gl::VboMesh::Layout layout;
        layout.setStaticPositions();
        layout.setStaticIndices();
        layout.setStaticColorsRGB();
        
        gl::VboMeshRef vboMesh = gl::VboMesh::create( (size_t) (slices + 2), (size_t) (slices + 2), layout, GL_TRIANGLE_FAN );
        vboMesh->bufferPositions( &positions.front(), positions.size() );
        vboMesh->bufferIndices( indices );
        vboMesh->bufferColorsRGB(colors);
        
        return vboMesh;
    }
}