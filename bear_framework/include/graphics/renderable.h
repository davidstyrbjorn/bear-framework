#pragma once

#include"transform.h"
#include"../core/color.h"

namespace bear { namespace graphics { 

	struct Renderable {
		/* Renderable data */
		Transform m_Transform;
		core::Color m_Color;
		std::string m_TextureName;

		/* Constructor(s) */
		Renderable();

		/* Loads the image size to this renderable */
		void setTextureNameWData(const std::string& a_TextureName);
	};

}} 