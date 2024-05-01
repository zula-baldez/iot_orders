import org.jetbrains.kotlin.gradle.tasks.KotlinCompile

plugins {
    id("org.springframework.boot") version "3.2.4"
    id("io.spring.dependency-management") version "1.1.4"
    kotlin("plugin.jpa") version "1.9.23"
    kotlin("jvm") version "1.9.23"
    kotlin("plugin.spring") version "1.9.23"
    kotlin("kapt") version "1.9.10"
}

group = "com.iot"
version = "0.0.1-SNAPSHOT"

java {
    sourceCompatibility = JavaVersion.VERSION_17
}

repositories {
    mavenCentral()
}
val coroutinesVersion = "1.8.0"
dependencies {
    implementation("org.springframework.boot:spring-boot-starter")
    implementation("org.jetbrains.kotlin:kotlin-reflect")
    implementation("org.springframework.boot:spring-boot-starter-data-jpa")
    implementation("org.springframework:spring-web:6.1.5")
    implementation("org.mapstruct:mapstruct:1.6.0.Beta1")
    implementation("org.jetbrains.kotlinx:kotlinx-coroutines-core:$coroutinesVersion")
    implementation("org.reactivestreams:reactive-streams:1.0.4")
     implementation("io.projectreactor:reactor-core:3.6.5")

    kapt("org.mapstruct:mapstruct-processor:1.6.0.Beta1")
    implementation("org.awaitility:awaitility:4.2.0")
    runtimeOnly("org.postgresql:postgresql")
// https://mvnrepository.com/artifact/org.jetbrains.kotlinx/kotlinx-coroutines-reactive
    runtimeOnly("org.jetbrains.kotlinx:kotlinx-coroutines-reactive:1.8.0")
// https://mvnrepository.com/artifact/org.jetbrains.kotlinx/kotlinx-coroutines-reactor
    runtimeOnly("org.jetbrains.kotlinx:kotlinx-coroutines-reactor:1.8.0")

// https://mvnrepository.com/artifact/org.springframework.boot/spring-boot-starter-webflux
    implementation("org.springframework.boot:spring-boot-starter-webflux:3.2.4")
    testImplementation("org.springframework.boot:spring-boot-starter-test")
}

tasks.withType<KotlinCompile> {
    kotlinOptions {
        freeCompilerArgs += "-Xjsr305=strict"
        jvmTarget = "17"
    }
}


tasks.withType<Test> {
    useJUnitPlatform()
}
