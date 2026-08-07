class Solution {
public:
    // Approach-1 -> Using HashMap
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    Node* copyRandomList(Node* head) {

        // If the original list is empty
        if (head == nullptr)
            return nullptr;

        // Map: Original Node -> Copied Node
        unordered_map<Node*, Node*> mp;

        // Create the head of the copied list
        Node* newHead = new Node(head->val);

        // Store the mapping of original head to copied head
        mp[head] = newHead;

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        // --- First Pass ---
        // Create all copied nodes.
        // Connect their next pointers.
        // Store mapping between original and copied nodes.
        while (oldTemp != nullptr) {

            Node* copyNode = new Node(oldTemp->val);

            mp[oldTemp] = copyNode;

            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // ---Second Pass ---
        // Traverse both lists together.
        // Use the hashmap to assign the random pointers.
        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != nullptr) {

            // The copied node's random should point to
            // the copy of oldTemp's random node.
            newTemp->random = mp[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};