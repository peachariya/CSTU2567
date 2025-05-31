```mermaid
graph TD
    subgraph "ผู้ใช้งาน (Internet User)"
        User[<i class='fa fa-user'></i> ผู้ใช้งาน]
    end

    subgraph "AWS Cloud"
        subgraph "VPC (Virtual Private Cloud)"
            IGW[<i class='fa fa-cloud'></i> Internet Gateway]

            subgraph "Region"
                ALB[<i class='fa fa-balance-scale'></i> Application Load Balancer (ALB)]
                ASG[<i class='fa fa-users'></i> Auto Scaling Group (ASG)]

                subgraph "Availability Zone A"
                    style AZ_A fill:#E6F3FF,stroke:#007bff,stroke-width:2px
                    PublicSubnetA[Public Subnet A]
                    EC2_A1[<i class='fa fa-server'></i> EC2 Instance]
                    EC2_A2[<i class='fa fa-server'></i> EC2 Instance]
                    PublicSubnetA -.-> EC2_A1
                    PublicSubnetA -.-> EC2_A2
                end

                subgraph "Availability Zone B"
                    style AZ_B fill:#E6F3FF,stroke:#007bff,stroke-width:2px
                    PublicSubnetB[Public Subnet B]
                    EC2_B1[<i class='fa fa-server'></i> EC2 Instance]
                    EC2_B2[<i class='fa fa-server'></i> EC2 Instance]
                    PublicSubnetB -.-> EC2_B1
                    PublicSubnetB -.-> EC2_B2
                end

                subgraph "Availability Zone C"
                    style AZ_C fill:#E6F3FF,stroke:#007bff,stroke-width:2px
                    PublicSubnetC[Public Subnet C]
                    EC2_C1[<i class='fa fa-server'></i> EC2 Instance]
                    EC2_C2[<i class='fa fa-server'></i> EC2 Instance]
                    PublicSubnetC -.-> EC2_C1
                    PublicSubnetC -.-> EC2_C2
                end
            end

            %% Security Groups
            SG_ALB[<i class='fa fa-shield-alt'></i> Security Group (ALB)]
            SG_EC2[<i class='fa fa-shield-alt'></i> Security Group (EC2)]

            %% Connections and Traffic Flow
            User -- HTTP/HTTPS Traffic --> IGW
            IGW -- Routes Traffic to --> ALB

            %% ALB spans across Public Subnets in multiple AZs
            ALB -- Deployed in --> PublicSubnetA
            ALB -- Deployed in --> PublicSubnetB
            ALB -- Deployed in --> PublicSubnetC

            %% ALB distributes traffic to Target Group (ASG)
            ALB -- Distributes Traffic to --> ASG

            %% ASG manages EC2 instances across AZs
            ASG -- Manages & Launches --> EC2_A1
            ASG -- Manages & Launches --> EC2_A2
            ASG -- Manages & Launches --> EC2_B1
            ASG -- Manages & Launches --> EC2_B2
            ASG -- Manages & Launches --> EC2_C1
            ASG -- Manages & Launches --> EC2_C2

            %% Route Tables (Implied: Public Subnets route 0.0.0.0/0 to IGW)
            PublicSubnetA -- Route Table (to IGW) --> IGW
            PublicSubnetB -- Route Table (to IGW) --> IGW
            PublicSubnetC -- Route Table (to IGW) --> IGW

            %% Security Group Associations
            ALB -- Protected by --> SG_ALB
            EC2_A1 -- Protected by --> SG_EC2
            EC2_A2 -- Protected by --> SG_EC2
            EC2_B1 -- Protected by --> SG_EC2
            EC2_B2 -- Protected by --> SG_EC2
            EC2_C1 -- Protected by --> SG_EC2
            EC2_C2 -- Protected by --> SG_EC2

            %% Security Group Rules (Conceptual - not directly drawn as connections)
            %% SG_ALB allows HTTP/S from Internet (0.0.0.0/0)
            %% SG_EC2 allows traffic from SG_ALB on application port
        end
    end

    classDef default fill:#f9f9f9,stroke:#333,stroke-width:2px,color:#333;
    classDef internet fill:#fff,stroke:#ccc,stroke-width:2px;
    classDef vpc fill:#E9D8FD,stroke:#9B59B6,stroke-width:2px;
    classDef region_group fill:#F4F6F6,stroke:#7F8C8D,stroke-width:1px;
    classDef subnet fill:#D5F5E3,stroke:#2ECC71,stroke-width:1px;
    classDef component_aws fill:#FFF9C4,stroke:#FBC02D,stroke-width:2px;

    class User internet;
    class VPC vpc;
    class PublicSubnetA,PublicSubnetB,PublicSubnetC subnet;
    class Region region_group;
    class ALB,ASG,EC2_A1,EC2_A2,EC2_B1,EC2_B2,EC2_C1,EC2_C2,IGW,SG_ALB,SG_EC2 component_aws;