#include "Renderer.h"

#include <SDL2-2.28.0/include/SDL_ttf.h>

namespace ane {
	Renderer globalRenderer;

	bool Renderer::Initialize() {
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();

		return true;
	}

	void Renderer::Shutdown() {
		SDL_DestroyRenderer(this->renderer);
		SDL_DestroyWindow(this->window);
		TTF_Quit();
	}

	void Renderer::CreateWindow(const std::string& title, int width, int height) {
		this->width = width;
		this->height = height;
		this->title = title;

		this->window = SDL_CreateWindow(title.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}

	void Renderer::BeginFrame() {
		SDL_RenderClear(this->renderer);
	}

	void Renderer::EndFrame() {
		SDL_RenderPresent(this->renderer);
	}

	void Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
		SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
	}

	void Renderer::DrawLine(int x1, int y1, int x2, int y2) {
		SDL_RenderDrawLine(this->renderer, x1, y1, x2, y2);
	}

	void Renderer::DrawLine(float x1, float y1, float x2, float y2) {
		SDL_RenderDrawLineF(this->renderer, x1, y1, x2, y2);
	}

	void Renderer::DrawPoint(int x, int y) {
		SDL_RenderDrawPoint(this->renderer, x, y);
	}

	void Renderer::DrawPoint(float x, float y) {
		SDL_RenderDrawPointF(this->renderer, x, y);
	}
}