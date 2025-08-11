#include "BTT_FindPlayer.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

UBTT_FindPlayer::UBTT_FindPlayer()
{
	NodeName = TEXT("Find Player");
	PlayerKey.SelectedKeyName = "TargetPlayer";
}

EBTNodeResult::Type UBTT_FindPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (PlayerCharacter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsObject(PlayerKey.SelectedKeyName, PlayerCharacter);
	
	return EBTNodeResult::Succeeded;
}