#pragma once

#include "CoreMinimal.h"
#include "JamResourceTypes.generated.h"

UENUM(BlueprintType)
enum class EJamBalanceAmount : uint8
{
	Small,
	Medium,
	Large
};

UENUM(BlueprintType)
enum class EJamBalanceType : uint8
{
	Hell,
	Heaven
};

UENUM(BlueprintType)
enum class EJamBalanceThreshold : uint8
{
	NoChange,
	Small,
	Medium,
	Large,
	Danger,
	Maxed
};
