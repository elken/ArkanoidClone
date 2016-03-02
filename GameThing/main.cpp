#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "constants.h"
#include "Ball.h"
#include "Bat.h"
#include "Block.h"

void checkBatHitBall(Bat& bat, Ball& ball) {
	if (!Util::isIntersecting(bat, ball)) return;
	
	ball.setY(-BALL_VELOCITY);
	if (ball.getX() < bat.getX())
		ball.setX(-BALL_VELOCITY);
	else
		ball.setX(BALL_VELOCITY);
}

void checkBallHitBlock(Block& block, Ball& ball) {
	if (!Util::isIntersecting(block, ball)) return;

	block.destroy();
	float overlapgetLeft{ ball.getRight() - block.getLeft() };
	float overlapgetRight{ block.getRight() - ball.getLeft() };
	float overlapgetTop{ ball.getBottom() - block.getTop() };
	float overlapBottom{ block.getBottom() - ball.getTop() };
	bool ballFromgetLeft(abs(overlapgetLeft) < abs(overlapgetRight));
	bool ballFromgetTop(abs(overlapgetTop) < abs(overlapBottom));
	float minOverlapX{ ballFromgetLeft ? overlapgetLeft : overlapgetRight };
	float minOverlapY{ ballFromgetTop ? overlapgetTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
		ball.setX(ballFromgetLeft ? -BALL_VELOCITY : BALL_VELOCITY);
	else
		ball.setY(ballFromgetTop ? -BALL_VELOCITY : BALL_VELOCITY);
}
int main() {
	Ball ball{ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
	Bat bat{ WINDOW_WIDTH / 2, WINDOW_HEIGHT - 50 };
	std::vector<Block> blocks;

	for (auto x{ 0 }; x < BLOCK_COUNT_HORIZONTAL; ++x) {
		for (auto y{ 0 }; y < BLOCK_COUNT_VERTICAL; ++y) {
			blocks.emplace_back((x + 1) * (BLOCK_WIDTH + 3) + 22, (y + 2) * (BLOCK_HEIGHT + 3));
		}
	}


	sf::RenderWindow window({ WINDOW_WIDTH, WINDOW_HEIGHT }, "Shitty Arkanoid");
	window.setFramerateLimit(60);

	while(window.isOpen()) {
		window.clear(sf::Color::Black);
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch(event.type) {
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					if(event.key.code == sf::Keyboard::Escape) {
						window.close();
					}
					break;

				default:
					break;
			}
		}
		ball.update();
		bat.update();
		checkBatHitBall(bat, ball);

		for (auto& block : blocks) {
			checkBallHitBlock(block, ball);
		}

		blocks.erase(std::remove_if(std::begin(blocks), std::end(blocks), [](const Block& block) { return block.isDestroyed(); }), std::end(blocks));
		window.draw(ball.getShape());
		window.draw(bat.getShape());
		for (auto& block : blocks) {
			window.draw(block.getShape());
		}
		window.display();
	}

	return 0;
}
