#include "Zombies/AMyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Engine/Engine.h"

#define PRINT_MSG(msg) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, msg); }
#define PRINT_SUCCESS(msg) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, msg); }
#define PRINT_ERROR(msg) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, msg); }

AAMyAIController::AAMyAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void AAMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	UBlackboardComponent* BBCompRaw = BlackboardComponent.Get();
	if (UseBlackboard(BehaviorTreeAsset->BlackboardAsset, BBCompRaw))
	{
		RunBehaviorTree(BehaviorTreeAsset);
	}

	else
	{
		PRINT_ERROR(TEXT("OnPossess: BehaviorTreeAsset es NULO."));
	}
}

void AAMyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}