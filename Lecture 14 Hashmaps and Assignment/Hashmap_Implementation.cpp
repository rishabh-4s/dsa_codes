#include <iostream>
#include <string>
template <typename V>
class MapNode
{
private:
    string key;
    V value;
    MapNode *next;

    friend class ourmap;

public:
    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    MapNode<V> **buckets;
    int count;
    int numBuckets;

public:
    ourmap()
    {
        size = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
    }
    int size()
    {
        return count;
    }

private:
    int getBucketIndex(string key)
    {
        int hashcode = 0;

        int current_coff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashcode += key[i] * current_coff;
            hashcode = hashcode % numBuckets;
            current_coff += 37;
            current_coff = current_coff % numBuckets; // taaki out of int range na chle jaaye
        }

        return hashcode % numBuckets;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        coutn = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketCoutn; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        // agar vaha pehle se kuch hai
        while (head != NULL)
        {
            // yaha value update kr rhe hai toh count++ nhi kiya
            if (head->key == key)
                head->value = value;
            return;
            head = head->next;
        }

        // agar uss key par koi value nhi hai
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        cout++ : // new node bna ke data store kr rhe toh count increse kiya

                 double loadFactor = (1.0 * count / numBuckets); // int/int gives int example: 1/2 = 0, to get a double we multiply by 1.0
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                    buckets[numBuckets] = head->next;
                else
                    prev->next = head->next;

                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
                return head->value;
            head = head->next;
        }
        return 0;
    }
};
