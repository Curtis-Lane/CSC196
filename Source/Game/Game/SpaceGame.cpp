#include "SpaceGame.h"

#include "Player.h"
#include "Enemy.h"

//#include "Core/Core.h"
#include "Audio/AudioSystem.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Framework/Scene.h"

#include "Renderer/ModelManager.h"

bool SpaceGame::Initialize() {
	// Create font / text
	this->font = std::make_shared<ane::Font>("ArcadeClassic.ttf", 24);
	this->scoreText = std::make_unique<ane::Text>(this->font);
	this->scoreText->Create(ane::globalRenderer, "SCORE 0000", ane::Color(1.0f, 1.0f, 1.0f, 1.0f));

	this->titleText = std::make_unique<ane::Text>(this->font);
	this->titleText->Create(ane::globalRenderer, "AZTEROIDS", ane::Color(1.0f, 1.0f, 1.0f, 1.0f));

	// Load audio
	ane::globalAudioSystem.AddAudio("hiss3", "hiss3.wav");

	this->scene = std::make_unique<ane::Scene>();

	return true;
}

void SpaceGame::Shutdown() {
	//
}

void SpaceGame::Update(float deltaTime) {
	switch(this->state) {
		case State::Title:
			if(ane::globalInputSystem.GetKeyDown(SDL_SCANCODE_SPACE)) {
				this->state = State::StartGame;
			}
			break;
		case State::StartGame:
			this->score = 0;
			this->lives = 3;
			this->state = State::StartLevel;
			break;
		case State::StartLevel:
			this->scene->RemoveAll();
			{
				std::unique_ptr<Player> player = std::make_unique<Player>(200.0f, ane::Pi, ane::Transform(ane::vec2(400, 300), 0.0f, 10.0f), ane::globalModelManager.Get("creeper.txt"));
				player->tag = "Player";
				player->game = this;
				this->scene->Add(std::move(player));
			}
			this->state = State::Game;
			break;
		case State::Game:
			this->spawnTimer += deltaTime;
			if(this->spawnTimer >= this->spawnTime) {
				this->spawnTimer = 0.0f;

				std::unique_ptr enemy = std::make_unique<Enemy>(ane::randomf(75.0f, 150.0f), ane::Pi, ane::Transform(ane::vec2(ane::random(ane::globalRenderer.GetWidth()), ane::random(ane::globalRenderer.GetHeight())), ane::randomf(ane::TwoPi), 6), ane::globalModelManager.Get("enemy.txt"));
				enemy->tag = "Enemy";
				enemy->game = this;
				this->scene->Add(std::move(enemy));
			}
			this->scoreText->Create(ane::globalRenderer, "SCORE " + std::to_string(this->score), ane::Color(1.0f, 1.0f, 1.0f, 1.0f));
			break;
		case State::PlayerDead:
			if(this->lives == 0) {
				this->state = State::GameOver;
			} else {
				this->state = State::StartLevel;
			}

			break;
		case State::GameOver:
			std::cout << "OUT OF LIVES!\n";
			break;
		default:
			break;
	}
		
	this->scene->Update(deltaTime);
}

void SpaceGame::Draw(ane::Renderer& renderer) {
	if(this->state == State::Title) {
		this->titleText->Draw(renderer, 335, 300);
	}

	this->scoreText->Draw(renderer, 40, 30);
	this->scene->Draw(renderer);
}
