#pragma once

namespace JamConstants
{
	extern const FName InteractActionName;
	
	constexpr int32 HeavenBalance = 100;
	constexpr int32 HellBalance = -100;
	
	constexpr int32 BalanceSmallAmount = 1;
	constexpr int32 BalanceMediumAmount = 30;
	constexpr int32 BalanceLargeAmount = 40;
	
	constexpr int32 BalanceSmallThreshold = 20;
	constexpr int32 BalanceMediumThreshold = 50;
	constexpr int32 BalanceLargeThreshold = 75;
	constexpr int32 BalanceDangerThreshold = 90;
};
