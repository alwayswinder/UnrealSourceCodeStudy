// Copyright fpwong. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "BlueprintAssistSettings.h"
#include "FormatterInterface.h"

class FBAGraphHandler;

class BLUEPRINTASSIST_API FBehaviorTreeGraphFormatter final
	: public FFormatterInterface
{
public:
	TSharedPtr<FBAGraphHandler> GraphHandler;
	FBAFormatterSettings FormatterSettings;
	FEdGraphFormatterParameters FormatterParameters;

	TSet<UEdGraphNode*> FormattedNodes;
	virtual TSet<UEdGraphNode*> GetFormattedNodes() override { return FormattedNodes; }

	UEdGraphNode* RootNode;
	virtual UEdGraphNode* GetRootNode() override { return RootNode; }

	FBehaviorTreeGraphFormatter(TSharedPtr<FBAGraphHandler> InGraphHandler, const FEdGraphFormatterParameters& InFormatterParameters);

	virtual ~FBehaviorTreeGraphFormatter() override { }

	virtual void FormatNode(UEdGraphNode* Node) override;

	virtual FBAFormatterSettings GetFormatterSettings() override;

	virtual FEdGraphFormatterParameters& GetFormatterParameters() override { return FormatterParameters; }

	virtual bool ShouldIgnoreComment(TSharedPtr<FBACommentContainsNode> ContainsNode) override { return true; }

private:
	void FormatNodes(UEdGraphNode* Node, TSet<UEdGraphNode*>& VisitedNodes) const;
};
