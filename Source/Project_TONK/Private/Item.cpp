// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

DEFINE_LOG_CATEGORY(LogTONK);

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Couch.SM_Couch"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Ground_Moss.M_Ground_Moss"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	UE_LOG(LogTONK, Warning, TEXT("%s Constructor"), *GetName());

}

void AItem::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UE_LOG(LogTONK, Warning, TEXT("%s PostInitializeComponents"), *GetName());
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTONK, Warning, TEXT("%s BeginPlay"), *GetName());
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItem::Destroyed()
{
	UE_LOG(LogTONK, Warning, TEXT("%s Destroyed"), *GetName());
	Super::Destroyed();
}

void AItem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UE_LOG(LogTONK, Warning, TEXT("%s EndPlay"), *GetName());
	Super::EndPlay(EndPlayReason);
}