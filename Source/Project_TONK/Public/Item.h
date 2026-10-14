// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTONK, Warning, All);

UCLASS()
class PROJECT_TONK_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	virtual void PostInitializeComponents()override;
	virtual void BeginPlay() override;
	virtual void Tick(float Deltatime) override;
	virtual void Destroyed() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
