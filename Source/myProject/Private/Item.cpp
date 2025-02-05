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

//������ - �޸𸮿� ����. ���ѹ� ȣ��.
//PostinitiallizeComponents()-������Ʈ�� �ϼ��� ���� ȣ��. ������Ʈ���� ������ �ְ�ޱ�, ��ȣ�ۿ�
// BeginPlay()-��ġ spawn����
//Tick(float DeltaTime)-�������Ӹ��� ȣ���
//Destroyedd()- �����Ǳ� ������ ȣ��ȴ�.
//EndPlay()-��������,
//D�� �θ��� E�� ȣ��� �ݴ�� �Ͼ�� ����

//FRotator(0.0f, 90.0f, 0.0f)); pitch, yaw, roll ����