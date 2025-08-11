#include "Zombies/AMyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"

#define PRINT_MSG(msg) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, msg); }
#define PRINT_SUCCESS(msg) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, msg); }
#define PRINT_ERROR(msg) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, msg); }

AAMyAIController::AAMyAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Script/AIModule.BehaviorTree'/Game/Voxels/Core/BT_EnemyAI.BT_EnemyAI'"));
	if (BTObject.Succeeded())
	{
		BehaviorTreeAsset = BTObject.Object;
	}
}

// CAMBIAMOS LA LÓGICA DE OnPossess
void AAMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	PRINT_MSG(TEXT("OnPossess LLAMADO."));
	
	if (BehaviorTreeAsset != nullptr)
	{
		BlackboardComponent->InitializeBlackboard(*BehaviorTreeAsset->BlackboardAsset);
	}
}

// AÑADIMOS LA FUNCIÓN Tick
void AAMyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (BlackboardComponent && BlackboardComponent->GetValueAsObject(TEXT("TargetPlayer")) == nullptr)
    {
        ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
        if (PlayerCharacter)
        {
            PRINT_SUCCESS(TEXT("Jugador ENCONTRADO en Tick. Iniciando Behavior Tree."));
            BlackboardComponent->SetValueAsObject(TEXT("TargetPlayer"), PlayerCharacter);
            BehaviorTreeComponent->StartTree(*BehaviorTreeAsset);
        }
        else
        {
            PRINT_ERROR(TEXT("Buscando jugador... (Tick)"));
        }
    }
}