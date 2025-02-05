// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPotion.h"

// Sets default values
AMyPotion::AMyPotion()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
	MaxLocation = GetActorLocation() + 20;
}

// Called when the game starts or when spawned
void AMyPotion::BeginPlay()
{
	Super::BeginPlay();
	OnItemPickedUp();
}

// Called every frame
void AMyPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
	
	float RunningTime = GetGameTimeSinceCreation();
	if (RunningTime > 700 * DeltaTime) {
		Move(0);
	}
	else if (RunningTime > 300 * DeltaTime) {
		Move(DeltaTime);
	}
	
}

void AMyPotion::ResetActorPosition()
{
	// (0, 0, 0) 위치로 되돌립니다.
	SetActorLocation(FVector::ZeroVector);
}

float AMyPotion::GetRotationSpeed() const
{
	return RotationSpeed;
}

void AMyPotion::Move(float DeltaTime)
{
	currentLocation = GetActorLocation();
	
	currentLocation += moveSpeed * DeltaTime;
	
	SetActorLocation(currentLocation);
	

}