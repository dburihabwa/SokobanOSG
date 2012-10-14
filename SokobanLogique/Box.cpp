#include "Box.h"
#include <osg/Geode>
#include <osgViewer/Viewer> 
#include <osg/Geometry> 
#include <osgDB/ReadFile> 
#include <osg\Texture2D>
#include <osg/ShapeDrawable>
#include <osg/Material>
using namespace osg;

Sokoban::Box::~Box(void)
{
}
ref_ptr<Geode> Sokoban::Box::createGeode()
{
	ref_ptr<Geode> noeudGeo = new Geode;
	noeudGeo->addDrawable(new ShapeDrawable(new osg::Box(Vec3(_x, _y, _z-0.5),0.8)));

	// create a simple material
	Material *material = new Material();
	material->setEmission(Material::FRONT, Vec4(0.8 ,0.8, 0.8, 1.0));

	// create a texture
	// load image for texture
	ref_ptr<Image> image = osgDB::readImageFile("textures/box.jpg");
	if (!image) {
		std::cout << "Couldn't load texture." << std::endl;
		return NULL;
	}
	ref_ptr<Texture2D> texture = new Texture2D;
	texture->setDataVariance(Object::DYNAMIC);
	texture->setFilter(Texture::MIN_FILTER, Texture::LINEAR_MIPMAP_LINEAR);
	texture->setFilter(Texture::MAG_FILTER, Texture::LINEAR);
	texture->setWrap(Texture::WRAP_S, Texture::CLAMP);
	texture->setWrap(Texture::WRAP_T, Texture::CLAMP);
	texture->setTextureSize(300,300);
	texture->setImage(image);

	// assign the material and texture to the sphere
	ref_ptr<StateSet> sphereStateSet = noeudGeo->getOrCreateStateSet();
	sphereStateSet->ref();
	sphereStateSet->setAttribute(material);
	sphereStateSet->setTextureAttributeAndModes(0, texture, StateAttribute::ON);
	return noeudGeo;
}
bool Sokoban::Box::canMove(Direction dir) const {
	return false;
}
bool Sokoban::Box::move(Direction dir) {
	return false;
}