#pragma once

#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "common.h"
#include "raytracer.h"

#include <thread>
#include <mutex>
#include <ctime>

class RayTracer {
	public:
		void render(int x, int y, int image_width = -1, int image_height = -1);
		void cancelRender();

		bool busy() { return isBusy; }
		bool done() { return isDone; }
		float progress() { return renderProgress; }
		float getRenderTime() { return renderTime; }

	private:
		bool isBusy = false,
			 isDone = false;
		bool cancelRequested = false;
		float renderProgress = 0.f;
		float renderTime = 0.f;
		std::thread* currentThread = nullptr;
};

#endif // !RAYTRACER_H
