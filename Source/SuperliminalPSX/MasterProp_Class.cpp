// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterProp_Class.h"
#include "Engine/TextureRenderTarget2D.h"

// Sets default values
AMasterProp_Class::AMasterProp_Class()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMasterProp_Class::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterProp_Class::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMasterProp_Class::ResizeTextureTarget(UTextureRenderTarget2D *Texture, int Width, int Height)
{
	Texture->ResizeTarget(Width, Height);
}

