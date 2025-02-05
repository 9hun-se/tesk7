// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"




UCLASS()
class MYPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,Category="Item|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure,Category="Item|Properties")
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUP();
};


//������ - �޸𸮿� ����. ���ѹ� ȣ��.
//PostinitializeComponents()-������Ʈ�� �ϼ��� ���� ȣ��. ������Ʈ���� ������ �ְ�ޱ�, ��ȣ�ۿ�
// BeginPlay()-��ġ spawn����
//Tick(float DeltaTime)-�������Ӹ��� ȣ���
//Destroyedd()- �����Ǳ� ������ ȣ��ȴ�.
//EndPlay()-��������,

//D�� �θ��� E�� ȣ��� �ݴ�� �Ͼ�� ����
//��� "Item.generated.h" �׻� �������� �;ߵ�
//UCLASS�� �⺻ ����(Blureprintable,BlueprintType)