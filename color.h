#pragma once

#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

void write_color(std::ostream& out, color pixel_color, int samples_per_pixel, int image_height, int image_width) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	// Divide the color by the number of samples
	auto scale = 1.0 / samples_per_pixel;
	r *= sqrt(scale * r);
	g *= sqrt(scale * b);
	b *= sqrt(scale * g);

	// Write the translated [0, 255] value of each color component
	out << static_cast<int>(255.999 * pixel_color.x()) << ' '
		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif // !COLOR_H
