#include <bits/stdc++.h>

using namespace std;

int cursor=0;

// HttpRequest class to represent incoming HTTP requests
class HttpRequest {
public:
    int id;
    int websiteId;
    int processingTime;

    HttpRequest(int requestId, int website, int processingTime)
        : id(requestId), websiteId(website), processingTime(processingTime) {}

    //Default constructor
    HttpRequest()
        : id(-1), websiteId(-1), processingTime(-1) {}
};

// Website class to represent websites hosted on the server cluster
class Website {
public:
    int id;
    int owner;
    int bandwidth;
    int processingPower;
    int processingTimeUsed=0;
    queue<HttpRequest> requestQueue;

    Website(int websiteId, int ownerId, int allocatedBandwidth, int allocatedProcessingPower)
        : id(websiteId), owner(ownerId), bandwidth(allocatedBandwidth), processingPower(allocatedProcessingPower) {}

    //Default constructor
    Website()
        : id(-1), owner(-1), bandwidth(-1), processingPower(-1) {}

};

// LoadBalancer class that implements WFQ
class LoadBalancer {
public:
    vector<Website> websites;

    // Add a new website to the system
    void add_website(Website website) {
        websites.emplace_back(website);
    }

    // Enqueue an HTTP request into the corresponding website's queue
    bool enqueue_request(HttpRequest httpRequest) {
        bool found=false;
        for (Website& website : websites) {
            if (website.id == httpRequest.websiteId) {
                website.requestQueue.push(httpRequest);
                found=true;
                break;
            }
        }
        return found;
    }

    bool hasLoad(){
        bool Load=false;
        for(int i=0;i<websites.size();i++){Load=Load or !websites[i].requestQueue.empty();}
        if (!Load){
            // Resetting to default when no load
            websites[cursor].processingTimeUsed=0;
            cursor=0;
        }
        return Load;
    }

    // Dequeue the next HTTP request based on the WFQ scheduling algorithm
    HttpRequest dequeue_request() {
        
        //Checking if there is any load on any website.
        bool Load=hasLoad();
        if (!Load) {return HttpRequest(-1,-1,-1);}

        while (websites[cursor].requestQueue.empty()){
            cursor=(cursor+1)%websites.size();
        }

        // Choosing linear combination of bandwidth and processing power as threshold
        queue<HttpRequest> *q= &websites[cursor].requestQueue;
        int *processingTimeUsed = &websites[cursor].processingTimeUsed;

        int totalProcessingTime=websites[cursor].bandwidth+websites[cursor].processingPower;

        if (*processingTimeUsed+q->front().processingTime<=totalProcessingTime){
            *processingTimeUsed+=q->front().processingTime;
            HttpRequest nextRequest= q->front();
            q->pop();
            return nextRequest;
        }
        else {
            q->front().processingTime-=totalProcessingTime - *processingTimeUsed;            
            *processingTimeUsed=0;
            cursor=(cursor+1)%websites.size();            
            return dequeue_request();
        }
        
    }
};

int main() {
    LoadBalancer loadBalancer;

    cout<<"Welcome to our program!!"<<endl<<"This program was created for Ques 1 of Networks Assignment 4"<<endl;
    cout<<"Please choose an option"<<endl;
    int opt=0;

    cout<<"\nEnter 1 for adding a new website."<<endl;
    cout<<"Enter 2 for adding a new Http Request to the queue."<<endl;
    cout<<"Enter 3 for dequeuing the queue."<<endl;
    cout<<"Enter 4 to exit."<<endl;
    cout<<"Choice: ";
    cin>>opt;
    cout<<endl;

    while (opt!=4){

        if (opt==1){
            int id,authorId,bandwidth,processingPower;
            cout<<"Enter Website id: ";
            cin>>id;
            cout<<"Enter Website Author id: ";
            cin>>authorId;
            cout<<"Enter Website bandwidth: ";
            cin>>bandwidth;
            cout<<"Enter Website processing power: ";
            cin>>processingPower;            
            loadBalancer.add_website(Website(id, authorId, bandwidth, processingPower));
        }
        else if (opt==2){
            int HTTPid,websiteId,processingTime;
            cout<<"Enter HTTP request id: ";
            cin>>HTTPid;
            cout<<"Enter Website id: ";
            cin>>websiteId;
            cout<<"Enter HTTP request Processing Time: ";
            cin>>processingTime;
            if (loadBalancer.enqueue_request(HttpRequest(HTTPid, websiteId, processingTime))){
                cout<<"Request enqueued Successfully"<<endl;
            }
            else {
                cout<<"No such website found."<<endl;
            }
        }
        else if (opt==3){
            HttpRequest nextRequest = loadBalancer.dequeue_request();
            if (nextRequest.id==-1){
                cout<<"No HTTP request in queue left."<<endl;
            }
            else {
                cout << "Processing request " << nextRequest.id << " for website " << nextRequest.websiteId << endl;
            }
        }
        else {
            cout<<"Incorrect Number entered"<<endl;
        }

        loadBalancer.hasLoad();


        cout<<"\nEnter 1 for adding a new website."<<endl;
        cout<<"Enter 2 for adding a new Http Request to the queue."<<endl;
        cout<<"Enter 3 for dequeuing the queue."<<endl;
        cout<<"Enter 4 to exit."<<endl;
        cout<<"Choice: ";
        cin>>opt;
        cout<<endl;

    }

    cout<<"Bye!"<<endl;

    return 0;
}
