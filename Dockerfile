# Stage 1: Builder
FROM ubuntu:22.04 AS builder
RUN apt-get update && apt-get install -y g++

WORKDIR /app
COPY main.cpp /app
RUN g++ -o myapp main.cpp

# Stage 2: Runtime
FROM debian:bookworm-slim
LABEL maintainer="Burin Timofey"

COPY --from=builder /app/myapp /app/myapp
CMD ["/app/myapp"]
