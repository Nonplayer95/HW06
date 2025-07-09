#include "RoActor.h"


ARoActor::ARoActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 45.0f;
}

void ARoActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARoActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FMath::IsNearlyZero(RotationSpeed))
	{
		return;
	}
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
}

