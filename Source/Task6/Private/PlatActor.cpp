#include "PlatActor.h"


APlatActor::APlatActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = 200.0f;
	MaxRange = 400.0f;


	StartLocation = FVector::ZeroVector;// BeginPlay에서 실제값 설정해주기
	bMovingRight = true;
	CurrentDistanceFromStart = 0.0f;

}

void APlatActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

void APlatActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	CurrentDistanceFromStart = FVector::Dist(StartLocation, CurrentLocation);

	// 우측 이동시
	if (bMovingRight)
	{
		if (CurrentDistanceFromStart<MaxRange)
		{
			// 계속 우측으로 이동
			FVector NewLocation = CurrentLocation + FVector(MoveSpeed * DeltaTime, 0, 0);
			SetActorLocation(NewLocation);
		}
		else
		{
			// 최대 거리 도달시, 방향전환
			bMovingRight = false;
		}
	}
	// 왼쪽 이동시
	else
	{
		if (CurrentDistanceFromStart > 10.0f)// 시작점 근처까지 왔는지 확인
		{
			// 계속 왼쪽으로 이동
			FVector NewLocation = CurrentLocation + FVector(-MoveSpeed * DeltaTime, 0, 0);
			SetActorLocation(NewLocation);
		}
		else
		{
			//시작 위치 도달, 방향 전환
			bMovingRight = true;
		}
	}
}

