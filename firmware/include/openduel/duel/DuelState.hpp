#pragma once

#include "openduel/duel/DuelPhase.hpp"

namespace openduel::duel {

class DuelState {
public:
	int getLifePoints(int player) const
	{
		if (!isValidPlayer(player)) {
			return 0;
		}

		return lifePoints_[player];
	}

	void setLifePoints(int player, int value)
	{
		if (!isValidPlayer(player)) {
			return;
		}

		lifePoints_[player] = clampLifePoints(value);
	}

	void adjustLifePoints(int player, int delta)
	{
		if (!isValidPlayer(player)) {
			return;
		}

		setLifePoints(player, lifePoints_[player] + delta);
	}

	int getActivePlayer() const
	{
		return activePlayer_;
	}

	int getSelectedPlayer() const
	{
		return selectedPlayer_;
	}

	void selectPlayer(int player)
	{
		if (!isValidPlayer(player)) {
			return;
		}

		selectedPlayer_ = player;
	}

	int getTurn() const
	{
		return turn_;
	}

	DuelPhase getPhase() const
	{
		return phase_;
	}

	void nextPhase()
	{
		switch (phase_) {
		case DuelPhase::Draw:
			phase_ = DuelPhase::Standby;
			break;
		case DuelPhase::Standby:
			phase_ = DuelPhase::Main1;
			break;
		case DuelPhase::Main1:
			phase_ = DuelPhase::Battle;
			break;
		case DuelPhase::Battle:
			phase_ = DuelPhase::Main2;
			break;
		case DuelPhase::Main2:
			phase_ = DuelPhase::End;
			break;
		case DuelPhase::End:
			endTurn();
			break;
		}
	}

	void endTurn()
	{
		activePlayer_ = 1 - activePlayer_;
		selectedPlayer_ = activePlayer_;
		++turn_;
		phase_ = DuelPhase::Draw;
	}

private:
	static constexpr int PlayerCount = 2;
	static constexpr int InitialLifePoints = 8000;

	static bool isValidPlayer(int player)
	{
		return player >= 0 && player < PlayerCount;
	}

	static int clampLifePoints(int value)
	{
		return value < 0 ? 0 : value;
	}

	int lifePoints_[PlayerCount] = {InitialLifePoints, InitialLifePoints};
	int activePlayer_ = 0;
	int selectedPlayer_ = 0;
	int turn_ = 1;
	DuelPhase phase_ = DuelPhase::Draw;
};

} // namespace openduel::duel
