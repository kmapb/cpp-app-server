# cpp-app-server
Basic skeleton of a modern C++ app server

Prompt: 

Implement a log parser that ingests lines like:

ts=... svc=A req=123 ev=send downstream=B
ts=... svc=B req=123 ev=recv

Tasks:
	•	Parse key=value pairs (robust to ordering).
	•	Group by req.
	•	Output per-request ordered timeline.
	•	Surface anomalies: missing recv, out-of-order timestamps, duplicate events.

Bonus (15–30m)
Add a flag: print the critical path per request (max gap between adjacent events).
