// Copyright (c) 2023-present Nino Saglia & Tim Verberne. All rights reserved.
// Written by Tim Verberne.

#pragma once

#include "CoreMinimal.h"
#include "Airplane.h"
#include "GameFramework/Pawn.h"
#include "Reaper.generated.h"


class UReaperAudioController;

/** The MQ-9 Reaper is a medium-sized unmanned aerial vehicle equipped with a turboprop engine.
 *  It boasts a long endurance and high altitude capability,
 *  making it suitable for a range of military operations. */
UCLASS(Abstract, Blueprintable, ClassGroup = "Aircraft", Meta = (DisplayName = "MQ-9 Reaper"))
class PROJECTFANBLADE_API AReaper : public AAirplane
{
	GENERATED_BODY()

private:
	float PropSpeed{0.0};

protected:



private:
	AReaper();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	
public:

	
	
protected:
	
};
