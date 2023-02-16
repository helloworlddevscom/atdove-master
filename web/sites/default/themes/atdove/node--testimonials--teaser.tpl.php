<section class="testimonials-wrapper">
    
    <div class="testimonials-image-wrapper">
        <?php print render($content['field_testimony_image']); ?>
    </div>

    <div class="testimonials-content-wrapper">
        <?php print render($content['body'][0]['#markup']); ?>
        <span class="testimonial-name"><?php print render($content['field_testimony_name'][0]['#markup']); ?></span>
        <span class="testimonial-organization"><?php print render($content['field_testimony_title_org'][0]['#markup']); ?></span>
    </div>
    
</section>