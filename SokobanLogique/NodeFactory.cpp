#include "NodeFactory.h"
#include <osg/Geode>
#include <osgViewer/Viewer> 
#include <osg/Geometry> 
#include <osgDB/ReadFile> 
#include <osg\Texture2D>
#include <osg/ShapeDrawable>
#include <osg/Material>
#include <osg/MatrixTransform>


ref_ptr<MatrixTransform> Sokoban::NodeFactory::createNode(size_t x,size_t y,size_t z, Type element) {
	ref_ptr<Geode> noeudGeo = new Geode;
	ref_ptr<ShapeDrawable> shape;
	char* textureImage;
	switch(element)
	{
	case GROUND :
		shape = new ShapeDrawable(new osg::Box(Vec3(0, 0, 0-0.05), 1,1,0.1));
		textureImage ="textures/rs-ground00.jpg";
		break;
	case BOX:
		shape = new ShapeDrawable(new osg::Box(Vec3(0, 0, 0-0.6),0.8));
		textureImage ="textures/box.jpg";
		break;
	case WALL:
		shape = new ShapeDrawable(new osg::Box(Vec3(0, 0, 0+0.5),1));
		textureImage ="textures/brickscolorhx8.jpg";
		break;
	case TARGET:
		shape = new ShapeDrawable(new osg::Box(Vec3(0, 0, 0), 1,1,0.1));
		textureImage ="textures/target.png";
		break;
	default:
		shape = new ShapeDrawable(new osg::Box(Vec3(0, 0, 0-0.05), 1,1,0.1));
		textureImage ="textures/rs-ground00.jpg";
		break;
	}
	noeudGeo->addDrawable(shape);

	// create a simple material
	Material *material = new Material();
	material->setEmission(Material::FRONT, Vec4(0.8, 0.8, 0.8, 1.0));

	// create a texture
	// load image for texture
	ref_ptr<Image> image = osgDB::readImageFile(textureImage);
	if (!image) {
		std::cout << "Couldn't load texture : " << textureImage <<std::endl;
		return NULL;
	}
	ref_ptr<Texture2D> texture = new Texture2D;
	texture->setDataVariance(Object::DYNAMIC);
	texture->setFilter(Texture::MIN_FILTER, Texture::LINEAR_MIPMAP_LINEAR);
	texture->setFilter(Texture::MAG_FILTER, Texture::LINEAR);
	texture->setWrap(Texture::WRAP_S, Texture::CLAMP);
	texture->setWrap(Texture::WRAP_T, Texture::CLAMP);
	texture->setImage(image);

	// assign the material and texture to the sphere
	ref_ptr<StateSet> sphereStateSet = noeudGeo->getOrCreateStateSet();
	sphereStateSet->ref();
	sphereStateSet->setAttribute(material);
	sphereStateSet->setTextureAttributeAndModes(0, texture, StateAttribute::ON);
	ref_ptr<MatrixTransform> matrix = new MatrixTransform;
	matrix->addChild(noeudGeo);
	matrix->setMatrix(Matrix::translate(x,y,z));
	//Rotation of -1.57 (Pi/2 = -90°) to see the level as the input string.
	matrix->postMult(Matrix::rotate(-1.57,Z_AXIS));
	return matrix;
}