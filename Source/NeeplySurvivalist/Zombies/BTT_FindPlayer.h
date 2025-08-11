#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "BTT_FindPlayer.generated.h"

UCLASS()
class NEEPLYSURVIVALIST_API UBTT_FindPlayer : public UBTTask_BlueprintBase
{
	GENERATED_BODY()

public:
	UBTT_FindPlayer();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FBlackboardKeySelector PlayerKey;
};