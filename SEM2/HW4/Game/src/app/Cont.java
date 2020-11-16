package app;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class Cont {

    @Bean
    public AI randomAI() {
        return new RandomAI();
    }

    @Bean
    public AI hardAI() {
        return new HardAI();
    }

}
