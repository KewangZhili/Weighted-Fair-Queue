**Weighted  Fair  Queuing  (WFQ)**:
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

WFQ  is  a  flow-based  queuing  algorithm  used  in  Quality  of Service (QoS) that does two things simultaneously: It schedules interactive traffic to the front of the  queue  to  reduce  response  time,  and  it  fairly  shares  the  remaining  bandwidth  between  high bandwidth flows. A stream of packets within a single session of a single application is known as flow  or  conversation.  WFQ  is  a  flow-based  method  that  sends  packets  over  the  network  and ensures packet transmission efficiency which is critical to interactivetraffic.1.Implement a load balancer for a web server cluster using WFQalgorithm. Scenario:Consider  a  cloud-based  web  server  cluster  that  serves  multiple  websites.  Each website owner has paid for a specific amount of bandwidth and processing power, which they should get proportionally. 

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Requirements**
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

:•Website Class:Create a websiteclass that representsa website hosted on the server cluster. Each  website  should  have  a  unique  ID,  owner,  and  queue  for  incoming requests. 
•HttpRequest Class:Implement  an HttpRequestclass  that  represents  an  incoming  HTTP request. Each request should have a unique ID, website ID, and processing time. •LoadBalancer Class:Create  a LoadBalancerclass  that  manages  the  incoming  requests  and implements   WFQ.   The   load   balancer   should   support   the   following operations: 
•add_website(website_id, owner_id, bandwidth, processing_power): Add a new website with specified ID, owner ID, allocated bandwidth, and processing power to the system. •enqueue_request(http_request): Enqueue an HTTP request into the corresponding website's queue. 
•dequeue_request(): Dequeue the next HTTP request based on the WFQ scheduling algorithm. 
•WFQ Scheduling:Implement the WFQ scheduling algorithm. Websites with higher allocated resources get served more frequently. 
  Test Case 1: Basic Load Balancing•Scenario:Two websites with equal allocated resources. 
  Test Case 2: Differential Bandwidth Allocation•Scenario:Websites have different allocated bandwidths.
  Test Case 3: Differential Processing Power Allocation•Scenario:Websites have different allocated processing powers. 
  Test Case 4: Equal Allocations•Scenario:Websites have equal allocated resources. 
  Test Case 5: Large Number of Requests•Scenario:Stress testing with a large number of HTTP requests. 
  Test Case 6: Empty Queues•Scenario:No requests in any website queues. 
  Test Case 7: Unequal Bandwidth and Processing Power•Scenario:Websites   have   both   unequal   bandwidth   and   processing   power allocations. 
  Test Case 8: Edge Case -Single Website•Scenario:Only one website presen
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
