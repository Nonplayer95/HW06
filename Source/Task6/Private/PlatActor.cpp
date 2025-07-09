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


	StartLocation = FVector::ZeroVector;// BeginPlay���� ������ �������ֱ�
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

	// ���� �̵���
	if (bMovingRight)
	{
		if (CurrentDistanceFromStart<MaxRange)
		{
			// ��� �������� �̵�
			FVector NewLocation = CurrentLocation + FVector(MoveSpeed * DeltaTime, 0, 0);
			SetActorLocation(NewLocation);
		}
		else
		{
			// �ִ� �Ÿ� ���޽�, ������ȯ
			bMovingRight = false;
		}
	}
	// ���� �̵���
	else
	{
		if (CurrentDistanceFromStart > 10.0f)// ������ ��ó���� �Դ��� Ȯ��
		{
			// ��� �������� �̵�
			FVector NewLocation = CurrentLocation + FVector(-MoveSpeed * DeltaTime, 0, 0);
			SetActorLocation(NewLocation);
		}
		else
		{
			//���� ��ġ ����, ���� ��ȯ
			bMovingRight = true;
		}
	}
}

