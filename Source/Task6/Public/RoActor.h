#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoActor.generated.h"

UCLASS()
class TASK6_API ARoActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARoActor();

protected:

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="RootComponents")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Rotation Settings")
	float RotationSpeed;


};
