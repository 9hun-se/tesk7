// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values
AItem::AItem()
{
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    //'/Game/Resources/Props/SM_Chair.SM_Chair';
    //'/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold';
    static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
    if (MeshAsset.Succeeded()) {
        StaticMeshComp->SetStaticMesh(MeshAsset.Object);
    }
    static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
    if (MaterialAsset.Succeeded()) {
        StaticMeshComp->SetMaterial(0,MaterialAsset.Object);
    }

    PrimaryActorTick.bCanEverTick = true;
    RotationSpeed = 90.0f;
        
}

void AItem::BeginPlay()
{
    Super::BeginPlay();

    OnItemPickedUP();
}

void AItem::Tick(float DeltaTime)
{
    Super:: Tick(DeltaTime);

    if (!FMath::IsNearlyZero(RotationSpeed))
    {
        AddActorLocalRotation(FRotator(RotationSpeed * DeltaTime, RotationSpeed * DeltaTime, 0.0f));
    }
}

void AItem::ResetActorPosition()
{
    SetActorLocation(FVector::ZeroVector);

}

float AItem::GetRotationSpeed() const
{
    return RotationSpeed;
}

//생성자 - 메모리에 생김. 딱한번 호출.
//PostinitiallizeComponents()-컴포넌트가 완성된 직후 호출. 컴포넌트끼리 데이터 주고받기, 상호작용
// BeginPlay()-배치 spawn직후
//Tick(float DeltaTime)-매프레임마다 호출됨
//Destroyedd()- 삭제되기 직전에 호출된다.
//EndPlay()-게임종료,
//D를 부르면 E도 호출됨 반대는 일어나지 않음

//FRotator(0.0f, 90.0f, 0.0f)); pitch, yaw, roll 순서