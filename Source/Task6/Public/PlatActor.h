#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"
#include "PlatActor.generated.h"

UCLASS()
class TASK6_API APlatActor : public AActor
{
	GENERATED_BODY()
	
public:	
	APlatActor();

protected:
	virtual void BeginPlay() override;


public:	
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	UStaticMeshComponent* StaticMeshComp;

	// 이동 관련 설정
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement Settings",meta=(ClampMin="-1000.0",ClampMax="1000.0"))
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Settings", meta = (ClampMin = "-1000.0", ClampMax = "2000.0"))
	float MaxRange;

	// 이동 상태 정보
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Movement Info")
	FVector StartLocation;

	// 이동 방향을 보여주는 디버그정보
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Movement Info")
	bool bMovingRight;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Movement Info")
	float CurrentDistanceFromStart;

};
