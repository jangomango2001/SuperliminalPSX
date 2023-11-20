// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MasterProp_Class.generated.h"

class UTextureRenderTarget2D;

UCLASS()
class SUPERLIMINALPSX_API AMasterProp_Class : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMasterProp_Class();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION(BlueprintCallable, Category = "Prop")
		void ResizeTextureTarget(UTextureRenderTarget2D *Texture, int Width, int Height);
};
